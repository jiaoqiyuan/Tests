#!/bin/bash
file="$1"
echo ${file##*.}
filetype="${file##*.}"
if [ $filetype == "run" -o $filetype == "bin" ]
then
	echo "This is *.run or *.bin file"
	#直接使用“./xxx.run或者./xxx.bin”安装	
	if [ $# == 2 ]
	then
		echo $2 | su root -c "chmod a+x '$1'"
		#To install westone products
		echo $2 | su root -c "/usr/local/wstsec/core/tool_protect stop 123456"
		echo $2 | su root -c "'$1' --nox11"
	elif [ $# == 1 ]
	then
		chmod a+x $1
		/usr/local/wstsec/core/tool_protect stop 123456
		$1 --nox11
	fi

	if [ $? -eq 0 ]
	then
		echo "安装run包或bin包成功"
	else
		echo "安装run包或bin包失败"
		exit 1
	fi

elif [ $filetype == "deb" ]
then
	#使用dpkg命令安装，如dpkg -i xxx.deb
	echo "是deb安装包"
	if [ $# == 2 ]
	then
		echo $2 | su root -c "dpkg -i '$1'"
	elif [ $# ==1 ]
	then
		dpkg -ivh $1
	fi

	if [ $? -eq 0 ]
	then
		echo "安装deb包成功"
	else
		echo "安装deb包失败"
		exit 1
	fi
		
elif [ $filetype == "rpm" ]
then
	#使用rpm命令安装，如rpm -i xxx.rpm
	echo "是rpm安装包"
	if [ $# == 2 ]
	then
		echo $2 | su root -c "rpm -i '$1'"
	elif [ $# == 1 ]
	then
		rpm -i $1
	fi
	if [ $? -eq 0 ]
	then
		echo "安装rpm包成功"
	else
		echo "安装RPM包失败"
		exit 1
	fi
elif [ $filetype == "sh" ]
then
    # 运行shell脚本
    echo "运行shell脚本"
    if [ $# == 2 ]
	then
		echo $2 | su root -c "chmod a+x '$1'"
        echo $2 | su root -c "'$1'"

	elif [ $# == 1 ]
	then
		chmod a+x $1
        `which bash` $1
	fi
	if [ $? -eq 0 ]
	then
		echo "运行shell脚本成功"
	else
		echo "运行shell脚本失败"
		exit 1
	fi
else
	echo "不被识别的安装包！"
	exit -2
fi

