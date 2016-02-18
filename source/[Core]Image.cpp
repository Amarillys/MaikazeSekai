//
#include "../header/[Core]Image.h"

Images::Images()
{
	// load support for the JPG and PNG image formats
	int flags = IMG_INIT_JPG | IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	if ((initted&flags) != flags) {
		SekaiBoom("IMG_Init: Failed to init required jpg and png support!\n");
		printf("IMG_Init: %s\n", IMG_GetError());
	}
}

Images::~Images()
{
	//Unload all the textures
	for (auto it = m_imgs.begin(); it != m_imgs.end(); ++it){
		SDL_DestroyTexture(it->tex);
		m_files->FreeRW(it->index);
	}
	IMG_Quit();
}

void Images::Load(int i_id, string i_path, int i_x, int i_y, int i_mtime, int i_a, int i_atime)
{
	//detect that if it exist an images,unload it
	for (auto it = m_imgs.begin(); it != m_imgs.end(); ++it)
	if (it->id == i_id)
		Unload(i_id);
	//create a new texture struct and add it to the vector
	Image newImg;
	if (m_files->ReadRW(i_path, &(newImg.rw), newImg.index)){
		if (!(newImg.sur = IMG_Load_RW(newImg.rw, AUTOFREE))){
			SekaiAlert("cannot analyse the picture file from " + i_path);
			return;
		}
		newImg.tex = SDL_CreateTextureFromSurface(m_ren, newImg.sur);
		newImg.id = i_id;
		SDL_QueryTexture(newImg.tex, NULL, NULL, &(newImg.rect.w), &newImg.rect.h);
		newImg.rect.x = i_x;
		newImg.rect.y = i_y;
		newImg.a = i_a;
		newImg.path = i_path;
		m_imgs.push_back(newImg);
	}
}

void Images::Unload(int i_id){
	for (auto it = m_imgs.begin(); it != m_imgs.end(); ++it){
		if (it->id == i_id){
			SDL_DestroyTexture(it->tex);
			m_files->FreeRW(it->index);
			return;
		}
	}
	SekaiAlert("The Texture :" + to_string(i_id) + "not found!");
}

void Images::OnDraw(){
	for (auto it = m_imgs.begin(); it != m_imgs.end(); ++it)
		SDL_RenderCopy(m_ren, it->tex, NULL, &it->rect);
}