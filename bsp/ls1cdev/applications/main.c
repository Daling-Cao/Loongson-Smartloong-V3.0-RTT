/*
 * File      : main.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2008 - 2017, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-05-10     zhuangwei    first version
 */

#include <rtthread.h>

int main(int argc, char** argv)
{   
	#if defined(RT_USING_DFS) && defined(RT_USING_DFS_ELMFAT)
		/* mount sd card fat partition 1 as root directory */
		if( dfs_mount("sd0", "/", "elm", 0, 0) == 0)
		{
			rt_kprintf("File System initialized!\n");
		}
		else
		{
			rt_kprintf("File System initialzation failed!\n");
		}
	#endif /* RT_USING_DFS && RT_USING_DFS_ELMFAT */


	/*网口EMAC初始化*/
		rt_hw_eth_init();

	#if defined(RT_USING_RTGUI)
	/*触摸屏使用SPI总线SPI1 CS0  初始化*/
		rtgui_touch_hw_init("spi10");
	#endif
	rt_kprintf("系统初始化完成！\n");
    return 0;
}
