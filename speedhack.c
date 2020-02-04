#include "rd_route/rd_route.h"
#include <mach-o/dyld.h>

float SPEED_MULTIPLIER = 2.0f;
void install(void) __attribute__ ((constructor));

void* (*scheduler_update)(void*,void*,float);
void* (*scheduler_update_tramp)(void*,void*,float);

void speedhack(void* s,void* a,float num) {
	scheduler_update_tramp(s,a,num);
	float* m_fDeltaTime = (float*)((intptr_t)s+0x90);
	*m_fDeltaTime = (*m_fDeltaTime)/SPEED_MULTIPLIER;
}

void install()
{
long base = _dyld_get_image_vmaddr_slide(0);
base += 0x100000000;
scheduler_update = base+0x2497a0;
rd_route(scheduler_update,speedhack,(void**)&scheduler_update_tramp);
}