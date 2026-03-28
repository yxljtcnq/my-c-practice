@echo off
chcp 65001 >nul
cls
echo ==============================================
echo          Gitee 一键提交推送 (my-c-practice)
echo ==============================================
echo.

:: 同步远程最新代码（防止冲突）
echo 正在拉取最新代码...
git pull
echo.

:: 添加所有代码文件
echo 正在添加文件...
git add .
echo.

:: 提交代码
echo 正在提交本地仓库...
git commit -m "更新C语言项目代码"
echo.

:: 推送到Gitee远程仓库
echo 正在推送到Gitee...
git push
echo.

echo ==============================================
echo                ✅ 推送完成！
echo ==============================================
echo.
pause