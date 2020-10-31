uniform float u_time; 
uniform vec3 u_resolution;

void main()
{
    vec2 uv = (2.*gl_FragCoord-u_resolution.xy)/u_resolution.y;
   
    float d = 1./abs(uv.y);
    vec2 pv = vec2(uv.x*d, d);
    pv.y +=u_time;
    pv *= 2.0;

    pv += 0.5;
    const float N = 64.0;
    vec2 w = fwidth(pv) + 0.001;
    vec2 a = pv + 0.5*w;
    vec2 b = pv - 0.5*w;
    vec2 i = (floor(a)+min(fract(a)*N,1.0)-floor(b)-min(fract(b)*N,1.0))/(N*w);
    float g = i.x + i.y - i.x*i.y;
    
    vec3 col = vec3(g);

    gl_FragColor = vec4(col,1.0);
     
}