#!/bin/bash
xrandr --output HDMI2 --right-of HDMI1 &
picom --config ${HOME}/.config/picom/picom.conf &
feh --bg-fill --randomize ${HOME}/repos/dwm/wallpaper &
thunderbird &
zoom &
obsidian &
github-desktop &
zotero &
firefox &
sioyek.AppImage ${HOME}/repos/journal/journal.pdf &
whatsapp.AppImage &
Vesktop.AppImage &
${HOME}/repos/dwm/status.sh &
/usr/share/PowerFolder/PowerFolder-Client.sh &
obs &
marktext &
# pycharm &
# remmina &
# ${HOME}/.local/bin/micromamba run spyder
# spotify &
# mlab -v 9.14 -d
# ${HOME}/cursor.AppImage &
# texstudio &
