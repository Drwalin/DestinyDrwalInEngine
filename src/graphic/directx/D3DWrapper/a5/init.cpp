
#pragma once

#include "../full.hpp"

bool al5_init_show_err(std::string func)
{
	std::string err = "al_"+func+"() failed";
	al_show_native_message_box(NULL, "AL5_INIT_ERROR", err.c_str(), " ", NULL, ALLEGRO_MESSAGEBOX_ERROR);
	return false;
}

bool allegro_full_init()
{
	if(!al_init())
		return al5_init_show_err("init");
	if(!al_install_keyboard())
		return al5_init_show_err("install_keyboard");
	if(!al_install_mouse())
		return al5_init_show_err("install_mouse");
	if(!al_install_audio())
		return al5_init_show_err("install_audio");
	if(!al_init_image_addon())
		return al5_init_show_err("init_image_addon");
	if(!al_init_acodec_addon())
		return al5_init_show_err("init_acodec_addon");
	if(!al_init_font_addon())
		return al5_init_show_err("init_font_addon");
	if(!al_init_native_dialog_addon())
		return al5_init_show_err("init_native_dialog_addon");
	if(!al_init_primitives_addon())
		return al5_init_show_err("init_primitives_addon");
	if(!al_init_ttf_addon())
		return al5_init_show_err("init_ttf_addon");
	if(!al_init_video_addon())
		return al5_init_show_err("init_video_addon");
	return true;
}



