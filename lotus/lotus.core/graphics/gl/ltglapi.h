#ifndef LTGLAPI_H
#define LTGLAPI_H

#include "../../lotustypes.h"
#include "../../defines.h"

LOTUS_API_ENTRY LTtexture2D ltglTexture2D(const char* texturePath);
LOTUS_API_ENTRY LTshaderProgram ltglShaderProgram(const char* vertexSrc, const char* fragmentSrc);

LOTUS_API_ENTRY LTvertexData ltglVertexDataBuffer(LTvertexBuffer buffer);
LOTUS_API_ENTRY LTvertexData ltglVertexData(u32 nAttributes, u32 nVertices, u32 nIndices, f32* vertices, u32* indices);

LOTUS_API_ENTRY LTshaderUniform ltglGetUniform(LTshaderProgram program, const char* name);
LOTUS_API_ENTRY void ltglSetUniform(LTshaderProgram program, LTGLuniformType type, const char* name, void* value);

#endif