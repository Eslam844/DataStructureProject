#include "taskschdulerinterface.h"

TaskSchdulerInterface::TaskSchdulerInterface()
{

}
void TaskSchdulerInterface::schedule(string taskName,string time){
    string command = "$Action = New-ScheduledTaskAction -Execute 'pwsh.exe' -Argument '-NonInteractive -NoLogo -NoProfile -File \"C:\\MyScript.ps1\"' /"
                     "$Trigger = New-ScheduledTaskTrigger -Once -At 3am/"
                     "$Task = New-ScheduledTask -Action $Action -Trigger $Trigger/";
}
