#!/bin/sh

function set_id {
	IFS="." read -a ID_PARTS <<< "${1}"

	sed -i -e "s/_APPLICATION_ID_/${1}/g" CMakeLists.txt
	sed -i -e "s/_PROJECT_NAME_/${ID_PARTS[-1]}/g" CMakeLists.txt

	echo "Project initialized as '${1}'"
}

read -p "ProjectID [default: de.anschu.GtkmmApplicationTemplate]: " PROJECT_ID

if [[ ! $PROJECT_ID ]]
then
	PROJECT_ID="de.anschu.GtkmmApplicationTemplate"
fi

set_id $PROJECT_ID
