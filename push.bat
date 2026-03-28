@echo off
chcp 65001 >nul
cls
echo ==============================================
echo          Gitee 一键提交推送 (带备注)
echo ==============================================
echo.

:: 让你自己输入备注
set /p msg=请输入本次提交的备注（例如：修复bug、新增代码）：
echo.

:: 拉取最新代码
echo [1/4] 拉取最新代码...
git pull
echo.

:: 添加所有文件
echo [2/4] 添加文件...
git add .
echo.

:: 提交（使用你输入的备注）
echo [3/4] 提交代码：%msg%
git commit -m "%msg%"
echo.

:: 推送到Gitee
echo [4/4] 推送到Gitee...
git push
echo.

echo ==============================================
echo                ✅ 推送完成！
echo ==============================================
echo.
pause