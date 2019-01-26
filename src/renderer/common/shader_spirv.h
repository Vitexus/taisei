/*
 * This software is licensed under the terms of the MIT-License
 * See COPYING for further information.
 * ---
 * Copyright (c) 2011-2019, Lukas Weber <laochailan@web.de>.
 * Copyright (c) 2012-2019, Andrei Alexeyev <akari@alienslab.net>.
 */

#ifndef IGUARD_renderer_common_shader_spirv_h
#define IGUARD_renderer_common_shader_spirv_h

#include "taisei.h"

#include "shader_defs.h"

typedef enum SPIRVTarget {
	SPIRV_TARGET_OPENGL_450,
	SPIRV_TARGET_VULKAN_10,
	SPIRV_TARGET_VULKAN_11,
} SPIRVTarget;

typedef enum SPIRVOptimizationLevel {
	SPIRV_OPTIMIZE_NONE,
	SPIRV_OPTIMIZE_SIZE,
	SPIRV_OPTIMIZE_PERFORMANCE,
} SPIRVOptimizationLevel;

typedef struct SPIRVCompileOptions {
	SPIRVTarget target;
	SPIRVOptimizationLevel optimization_level;
	bool debug_info;
	const char *filename;
} SPIRVCompileOptions;

typedef struct SPIRVDecompileOptions {
	const ShaderLangInfo *lang;
} SPIRVDecompileOptions;

typedef struct SPIRVTranspileOptions {
	const ShaderLangInfo *lang;
	SPIRVOptimizationLevel optimization_level;
	const char *filename;
} SPIRVTranspileOptions;

void spirv_init_compiler(void);
void spirv_shutdown_compiler(void);
bool spirv_compile(const ShaderSource *in, ShaderSource *out, const SPIRVCompileOptions *options) attr_nonnull(1, 2, 3);
bool spirv_decompile(const ShaderSource *in, ShaderSource *out, const SPIRVDecompileOptions *options) attr_nonnull(1, 2, 3);
bool spirv_transpile(const ShaderSource *in, ShaderSource *out, const SPIRVTranspileOptions *options);

#endif // IGUARD_renderer_common_shader_spirv_h