#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in mat4 model;
layout (location = 5) in vec3 aColor;

uniform mat4 view;
uniform mat4 projection;

out vec3 color;

void main()
{
  gl_Position = projection * view * model * vec4(aPos, 1.0);
  color = aColor;
}
