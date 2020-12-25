#version 330

out vec4 color;


in vec3 pass_color;

uniform float animation;

void main(){


	color = vec4(pass_color * animation, 1);
}