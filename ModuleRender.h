#ifndef MODULERENDER_H
#define MODULERENDER_H

#include "Module.h"
#include "SDL/include/SDL_rect.h"
#include "Point.h"

#define MODULE_RENDER "ModuleRender"
#define VSYNC "Config.Modules.Render.Vsync"
#define DEFAULT_SPEED "Config.Modules.Render.DefaultBlitSpeed"

struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;

class ModuleRender : public Module
{
public:
	ModuleRender();
	~ModuleRender();

	bool Init();
	update_status PreUpdate();
	update_status Update();
	update_status PostUpdate();
	bool CleanUp();

	bool BlitCentered(SDL_Texture* texture, SDL_Rect* section, float speed);
	bool BlitCentered(SDL_Texture* texture, SDL_Rect* section);
	bool Blit(SDL_Texture* texture, iPoint position, SDL_Rect* section);
	bool Blit(SDL_Texture* texture, iPoint position, SDL_Rect* section, float speed);
	bool DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera = true);

private:
	bool ConstantConfig();

public:
	SDL_Renderer* renderer = nullptr;
	SDL_Rect camera = { 0,0,0,0 };

private:
	int iSCREENSIZE = 0;
	int iSCREENWIDTH = 0;
	int iSCREENHEIGHT = 0;
	float fDEFAULT_SPEED = 1.0f;
	bool bVSYNC = true;
};

#endif // !MODULERENDER_H
