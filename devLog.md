如果你clone下来一个别人的仓库，在此基础上完成你的代码，推送到自己的仓库可能遇到如下问题：
error: remote origin already exists.表示远程仓库已存在。
因此你要进行以下操作：
1、先输入git remote rm origin 删除关联的origin的远程库
2、关联自己的仓库 git remote add origin https://gitee.com/xxxxxx.git
3、最后git push origin master，这样就推送到自己的仓库了。