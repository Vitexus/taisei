/*
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2018, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2018, Andrei Alexeyev <akari@alienslab.net>.
 */

#pragma once
#include "taisei.h"

#include "stage.h"

void stage_draw_preload(void);
void stage_draw_hud(void);
void stage_draw_foreground(void);
void stage_draw_scene(StageInfo *stage);
bool stage_should_draw_particle(Projectile *p);
