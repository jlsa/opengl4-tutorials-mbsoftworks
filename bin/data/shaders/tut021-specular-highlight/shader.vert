#version 440 core

uniform struct
{
    mat4 projectionMatrix;
    mat4 viewMatrix;
    mat4 modelMatrix;
    mat3 normalMatrix;
} matrices;

layout(location = 0) in vec3 vertexPosition;
layout(location = 1) in vec2 vertexTexCoord;
layout(location = 2) in vec3 vertexNormal;

smooth out vec2 ioVertexTexCoord;
smooth out vec3 ioVertexNormal;
smooth out vec4 ioWorldPosition;
smooth out vec4 ioEyeSpacePosition;

void main()
{
    mat4 mvMatrix = matrices.viewMatrix * matrices.modelMatrix;
    mat4 mvpMatrix = matrices.projectionMatrix * mvMatrix;
    gl_Position = mvpMatrix * vec4(vertexPosition, 1.0);
    
    // Output all out variables
    ioVertexTexCoord = vertexTexCoord;
    ioVertexNormal = matrices.normalMatrix * vertexNormal;
    ioWorldPosition = matrices.modelMatrix * vec4(vertexPosition, 1.0);
    ioEyeSpacePosition = mvMatrix * vec4(vertexPosition, 1.0);
}