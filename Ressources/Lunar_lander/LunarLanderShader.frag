uniform vec3 u_resolution;
uniform float u_time;

#define iterations 17
#define formuparam 0.53

#define volsteps 20
#define stepsize 0.1

#define zoom   0.800
#define tile   0.850
#define speed  0.010 

#define brightness 0.0015
#define darkmatter 0.300
#define distfading 0.730
#define saturation 0.850

void main()
{
	vec2 uv=gl_FragCoord.xy/u_resolution.xy-0.5;
	uv.y*=u_resolution.y/u_resolution.x;
	vec3 dir=vec3(uv*zoom,1.);
	float time=u_time*speed+.25;
	
	vec3 from=vec3(1.0,0.5,0.5);
	from+=vec3(time*2.,time,-2.0);
	
        float s=0.1,fade=1.0;
	vec3 v=vec3(0.0);
	for (int r=0; r<volsteps; r++) 
        {
		vec3 p=from+s*dir*0.5;
		p = abs(vec3(tile)-mod(p,vec3(tile*2.)));
		float pa,a=pa=0.0;
		for (int i=0; i<iterations; i++) { 
			p=abs(p)/dot(p,p)-formuparam;
			a+=abs(length(p)-pa);
			pa=length(p);
		}
		float dm=max(0.0,darkmatter-a*a*0.001);
		a*=a*a;
		if (r>6) fade*=1.0-dm;
		v+=fade;
		v+=vec3(s,s*s,s*s*s*s)*a*brightness*fade; 
		fade*=distfading;
		s+=stepsize;
	}
	v=mix(vec3(length(v)),v,saturation); 
	gl_FragColor = vec4(v*.01,1.0);	
}
