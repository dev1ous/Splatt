uniform sampler2D LastPass;
uniform sampler2D DiffuseMap;
uniform vec3 AmbientLight;
uniform int LightCount;
uniform int PassNumber;

struct LightInfo
{
	vec3 position;
	vec3 color;
	float radius;
	float falloff;
};
const int MaxLights = 3;
uniform LightInfo Lights[MaxLights];

void main()
{
	vec4 pixel = texture2D(LastPass, gl_TexCoord[0].xy);
	vec4 diffusepixel = texture2D(DiffuseMap, gl_TexCoord[0].xy);
	vec4 finalPixel = (gl_Color * pixel);
	if (PassNumber == 1)
		finalPixel *= vec4(AmbientLight, 1.0);

	for (int i = 0; i < LightCount; i++)
	{
		vec3 L = Lights[i].position - gl_FragCoord.xyz;
		float distance = length(L);
		float d = max(distance - Lights[i].radius, 0.0);
		L /= distance;

		float attenuation = 1.0 / pow(d/Lights[i].radius + 1,2);
		attenuation = (attenuation - Lights[i].falloff) / (1.0 - Lights[i].falloff);
		attenuation = max(attenuation, 0.0);
		finalPixel += diffusepixel * ((vec4(Lights[i].color, 1.0) * attenuation));
	}
	gl_FragColor = finalPixel;
}