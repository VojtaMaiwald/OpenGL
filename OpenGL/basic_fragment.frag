#version 460 core

in vec4 outColor;
in vec2 outUV;
out vec4 FragColor;

uniform vec2 resolution;
uniform float time;
uniform sampler2D tex;

void main()
{

	vec2 center = resolution * 0.5f;
	vec2 pos = gl_FragCoord.xy;

	if (length(pos - center) < 50.f) {
		FragColor = texture2D(tex, outUV);
	}
	else{
		float i = gl_FragCoord.y / resolution.y;
		FragColor = outColor * vec4(i * abs(sin(time * i)), i * abs(sin(time * 2.f)), i * abs(sin(time * 0.5f)), 0.5f);
	}
		//FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);
}
