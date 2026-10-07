# Diary_demo

一个基于 Qt 6 的简易日记程序练习。

## 功能

- 新建并保存日记
- 使用 JSON 文件保存日记内容
- 在列表中显示已保存的日记
- 点击列表查看日记详情
- 使用 Windows Hello（PIN、指纹或人脸）验证访问身份

## 开发环境

- Qt 6.12
- C++17
- Qt Widgets
- MSVC 2022 64-bit
- Windows SDK / C++/WinRT

## 运行

使用 Qt Creator 打开 `Diary_demo.pro`，选择 MSVC 2022 64-bit 套件后构建运行。

> Windows Hello 使用 C++/WinRT 接口，因此该项目需要 MSVC 和 Windows SDK，不支持直接使用 MinGW 构建。

