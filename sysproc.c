#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}

int 
sys_exit(void)
{
  exit();
  return 0;
}

int
sys_exitStatus(void) // Lab 1 changes
{
  int status; // Lab 1 changes
  if(argint(0, &status) < 0) // Lab 1 changes
    return -1; // Lab 1 changes
  exitStatus(status); // Lab 1 changes
  return 0;  // not reached
}

int
sys_wait(void) 
{
  int *status; // Lab 1 changes
  if (argptr(0, (char**) &status, sizeof(status)) < 0) // Lab 1 changes
    return -1; // Lab 1 changes
  return wait(status); // Lab 1 changes
}

int
sys_waitpid(void) // Lab 1 changes
{
  int pid; // Lab 1 changes
  int *status; // Lab 1 changes
  int options; // Lab 1 changes
  if (argptr(1, (char**) &status, sizeof(status)) < 0) // Lab 1 changes
    return -1; // Lab 1 changes
  if(argint(0, &pid) < 0) // Lab 1 changes
    return -1; // Lab 1 changes
  if(argint(2, &options) < 0) // Lab 1 changes
    return -1; // Lab 1 changes
  return waitpid(pid, status, options); // Lab 1 changes
}

int 
sys_changePriority(void) 
{
 int change; 
  if(argint(0, &change) < 0)
    return -1; 
 exitStatus(change); 
 return 0;  // not reached

}




/*
int
sys_debug(void)
{

  

  return debug();
}
*/
int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
