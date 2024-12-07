#include<iostream>
#include<iomanip>
#include<cmath>
#include<windows.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include<cstdio>
#include<cstdlib>
#include<direct.h>
#define reset "\033[0m"
#define red "\033[31m"
#define green "\033[32m"
#define yellow "\033[33m"
using namespace std;
int main()
{
    system("chcp 65001");//设置utf-8字符
    system("cls");
    cout << red << 'R' << green << 'G' << yellow << 'B' << reset << endl;//用于展示RGB显示
    string version = "0.3.4.1(开发beta版)电源更新";
    cout << "程序版本号：" << version << endl;
    ifstream infile("user.txt");//声明"infile"
    if (infile.is_open())
    {
        cout << "程序成功运行，已检测到用户文件，准备启动" << endl;
    }
    else
    {
        cout << "程序成功运行，未检测到用户文件，正在尝试创建. . ." << endl;
        infile.close();
        Sleep(1000);
        ofstream outfile("user.txt");//声明"outfile"
        if (outfile.is_open())
        {
            outfile << "admin" << endl << "123456";
            outfile.close();
        }
        else
        {
            cout << "用户文件创建失败，程序将在2秒后退出" << endl;
            Sleep(2000);
            return -1;
        }
        cout << "默认账户名：admin" << endl;
        cout << "默认密码：123456" << endl;
    }
    infile.close();
    Sleep(1000);
    cout << "所有配置均已检测完毕，请按下任意键启动用户登录器！" << endl;
    system("pause");
    while (true)
    {
    a:system("cls");
        string name;
        string password;
        cout << "请输入用户名以登录：";
        cin >> name;
        cout << "请输入密码：";
        cin >> password;
        cout << endl << "正在验证. . ." << endl;
        infile.open("user.txt");
        string name_n;
        int line = 1;
        int linee = 0;
        if (infile.is_open())
        {
            while (getline(infile, name_n))
            {
                linee++;
                if (linee == line)
                {
                    break;
                }
            }
        }
        else
        {
            cout << "[system/Error]:致命错误！无法打开用户文件，程序将在2秒后退出！" << endl;
            Sleep(2000);
            return -1;
        }
        infile.close();
        if (name_n == "")
        {
            cout << "[system/Error]:致命错误！ 用户文件中，用户名为空！请检测user.txt文件，以下是用户文件中的数据" << endl;
            Sleep(1000);
            infile.open("user.txt");
            if (infile.is_open())
            {
                while (getline(infile, name_n))
                {
                    cout << name_n << endl;
                }
                system("pause");
                return -1;
            }
            else
            {
                cout << "[system/Error]:致命错误！无法打开用户文件，程序将在2秒后退出" << endl;
                Sleep(2000);
                return -1;
            }
        }
        infile.close();
        infile.open("user.txt");
        string password_n;
        line = 2;
        linee = 0;
        if (infile.is_open())
        {
            while (getline(infile, password_n))
            {
                linee++;
                if (linee == line)

                    break;
            }
        }
        infile.close();
        if (linee < line)
        {
            cout << "[system/Error]:致命错误！用户文件中，找不到密码！用户文件已损坏！正在删除用户文件!程序将在3秒后退出！" << endl;
            if (remove("user.txt") == 0)
            {
                cout << "删除成功，准备关闭程序！" << endl;
                Sleep(3000);
                return -1;
            }
            else
            {
                cout << "无法删除，请手动删除，准备关闭程序" << endl;
                Sleep(3000);
                return -1;
            }
        }
        infile.close();
        if (password_n == "")
        {
            cout << "[system/Error]:致命错误！用户文件中，密码为空！请检测user.txt文件，以下是用户文件中的数据" << endl;
            Sleep(1000);
            infile.open("user.txt");
            if (infile.is_open())
            {
                while (getline(infile, password_n))

                {
                    cout << password_n << endl;
                }
                system("pause");
                return -1;
            }
        }
        if (name == name_n)//登录验证 检测用户名
        {
            if (password == password_n)//登录验证 检测密码
            {
                cout << "正确，1秒后即将登录系统！" << endl;
                Sleep(1000);
                break;
            }
            else
            {
                cout << " 错误！密码错误，3秒后即将重新登录！" << endl;
                Sleep(3000);
                system("pause");
            }
        }
        else if (password == password_n)
        {
            cout << "错误！用户名错误。3秒后即将重新登录！" << endl;
            Sleep(3000);
            system("pause");
        }
        else
        {
            cout << "错误！用户名和密码错误，3秒后即将重新登录！" << endl;
            Sleep(3000);
            system("pause");
        }
    }
    cout << "[system]:成功登录!" << endl;
    Sleep(1000);
    system("cls");
    while (true)
    {
        system("cls");
        cout << "【1】修改密码" << endl << "【2】修改用户名" << endl << "【3】重置用户文件" << endl << "【4】登出系统" << endl << "【5】启动Windo VC系统" << endl << "请输入序号" << endl;
        int akr;
        cin >> akr;
        if (akr == 1)
        {
            system("cls");
            cout << "请输入旧密码：";
            string b;
            cin >> b;
            infile.open("user.txt");
            string c;
            int line = 2;
            int linee = 0;
            if (infile.is_open())
            {
                while (getline(infile, c))
                {
                    linee++;
                    if (linee == line)
                    {
                        break;
                    }
                }
            }
            infile.close();
            if (c != b)
            {
                cout << "错误，密码错误！" << endl;
                Sleep(2000);
                system("pause");
                continue;
            }
            cout << "请输入新密码：";
            string password_n;
            cin >> password_n;
            string a;
            line = 1;
            linee = 0;
            infile.open("user.txt");
            if (infile.is_open())
            {
                while (getline(infile, a))
                {
                    linee++;
                    if (linee == line)
                    {
                        break;
                    }
                }
            }
            infile.close();
            ofstream outfile("user.txt");
            if (outfile.is_open())
            {
                outfile << a << endl;
                outfile << password_n;
            }
            Sleep(1000);
            cout << "密码成功修改!" << endl;
            system("pause");
        }
        if (akr == 2)
        {
            system("cls");
            cout << "请输入新用户名：";
            string a, b, c;
            cin >> a;
            infile.open("user.txt");
            int line = 2;
            int linee = 0;
            if (infile.is_open())
            {
                while (getline(infile, b))
                {
                    linee++;
                    if (linee == line)
                    {
                        break;
                    }
                }
            }
            infile.close();
            ofstream outfile("user.txt");
            if (outfile.is_open())
            {
                outfile << a << endl << b;
            }
            outfile.close();
            cout << "用户名修改成功" << endl;
            Sleep(1500);
        }
        if (akr == 3)
        {
            system("cls");
            cout << "正在重置用户文件" << endl;
            Sleep(1000);
            remove("user.txt");
            if (remove("user.txt"))
            {
                cout << "成功删除用户文件，正在尝试创建用户文件" << endl;
                Sleep(1000);
            }
            else
            {
                cout << "无法重置用户文件，请手动删除用户文件并重新运行程序" << endl;
                Sleep(3000);
                continue;
            }
            ofstream outfile("user.txt");
            if (outfile.is_open())
            {
                outfile << "admin" << endl << "123456";
            }
            outfile.close();
            cout << "重置用户文件成功！" << endl;
            continue;
        }
        if (akr == 4)
        {
            system("cls");
            cout << "正在注销你的登录" << endl;
            Sleep(1000);
            goto a;
        }
        if (akr == 5)
        {
            system("cls");
            cout << "正在启动Do UI界面...请稍后" << endl;
            Sleep(1000);
            break;
        }
    }
    cout << "欢迎" << endl;
    cout << "WINDO VC UI" << endl;
    Sleep(5000);
    system("cls");
    string wd;
    while (true)
    {
        system("cls");
        cout << "【1】打开原生桌面" << "      " << "【2】打开WD文件管理器" << "      " << "【3】设置" << "      " << "【4】电源选项" << "      " << "【5】DLL加载" << "      ";
        cout << endl << "请输入序号" << endl;

        int akr;
        cin >> akr;
        if (akr == 1)
        {
            system("cls");
            cout << "正在打开Windows资源管理器" << endl;
            system("explorer.exe");
            Sleep(1000);
            continue;
        }
        wd = "WD文件管理器";
        if (akr == 2)
        {
            system("cls");
            cout << "[" << wd << "]:" << "正在打开目录" << endl;
            cout << "默认目录：c:\\user\\your_name\\" << endl;
            wchar_t userProfile[MAX_PATH];
            GetEnvironmentVariableW(L"USERPROFILE", userProfile, MAX_PATH);
            SetCurrentDirectory(userProfile);
            while (true)
            {
                system("dir");
                cout << "请输入想要进入的文件夹或路径(到上级目录请输入..)(退出输入wd_exit):";
                wstring a;
                wcin >> a;
                system("cls");
                if (a == L"wd_exit")
                {
                    cout << "[WD文件管理器]:正在退出..." << endl;
                    SetCurrentDirectory(L"ds");
                    cout << "程序:" << wd << ":已退出" << endl;
                    Sleep(1000);
                    break;
                }
                if (SetCurrentDirectory(a.c_str()))
                {
                    wcout << "已进入目录:" << endl << a << endl;
                }
                else
                {
                    cout << "无法进入目录" << endl;
                }
            }
            continue;
        }

        //3号的功能...
        if (akr == 4)
        {
            while(true)
            {
                system("cls");
                cout << "【1】" << red << "关机" << endl << reset << "【2】" << green << "重启" << endl << reset << "【3】返回至主菜单" << "请输入序号" << endl;
                int ags;
                char agsc;
                cin >> ags;
                bool b = true;//存储是否为"特殊关机" false表示是 true 表示否
                switch (ags)
                {
                case 1:
                    cout << "确定要" << red << "关机" << reset << "吗？" << endl;
                    cout << "Tips: Y是,N否" << endl;
                    cin >> agsc;
                    if (agsc == 'Y' || agsc == 'y')
                    {
                        cout << "再见" << endl;
                        infile.close();
                        ifstream infile("config.txt");
                        int line = 1, linee = 0;
                        string a;
                        if (infile.is_open())
                        {
                            while (getline(infile, a))
                            {
                                linee++;
                                if (linee == line)
                                {
                                    break;
                                }
                            }
                            if (a != "true")
                                system("shutdown /s /t 0");
                            else
                                b = false;
                        }
                        else
                        {
                            system("shutdown /s /t 0");
                        }
                        Sleep(5000);
                        if (b == false)
                        {
                            return 2;
                        }
                        ofstream outfile;
                        (void)outfile.open("Crash.txt");
                        outfile << "超时  错误，无法关闭计算机,可能是\"shutdown\"损坏或丢失,重新安装操作系统或修复这个文件以解决";
                        outfile.close();
                        return 2;//为防止出现错误，使用返回
                    }
                    break;
                case 2:
                    cout << "确定要" << green << "重启" << reset << "吗？" << endl;
                    cout << "Tips: Y是,N否" << endl;
                    cin >> agsc;
                    if (agsc == 'Y' || agsc == 'y')
                    {
                        cout << "再见" << endl;
                        system("shutdown /r /t 0");
                        ofstream outfile("Crash.txt");
                        (void)outfile.is_open();
                        outfile << "超时  错误，无法重启计算机,可能是\"shutdown\"损坏或丢失,重新安装操作系统或修复这个文件以解决";
                        outfile.close();
                        return 2;//为防止出现错误，使用返回
                        //这里和上面一样
                    }
                case 3:
                    cout << green << "返回" << reset;
                    Sleep(1000);
                    ags = 10086;
                    break;
                default:
                    ags = 0;
                    cout << "请重试" << endl;
                    system("pause");
                    break;
                }
                if (ags == 10086)
                {
                    break;
                }
            }
            system("pause");
            continue;
        }

        if (akr == 5)
        {
            system("cls");
            cout << "欢迎使用【DLL加载器】" << endl;
            while (true)
            {
                cout << "【1】两个整数" << endl;
                cout << "【372】退出此功能" << endl;
                int a;
                cin >> a;
                if (a == 1)
                {
                    typedef int(*MathFunc)(int, int);
                    cout << "请输入DLL文件名：";
                    wstring  a;
                    wcin >> a;
                    HMODULE hModule = LoadLibrary(a.c_str());
                    if (hModule == NULL)
                    {
                        cout << red << "无法加载DLL，可能文件已经损坏或不存在，错误代码：" << yellow << GetLastError() << endl;
                        cout << reset;
                        system("pause");
                        system("cls");
                        continue;
                    }
                    else
                    {
                        cout << green << "成功加载DLL！" << reset << endl;
                    }
                    cout << "请输入要调用的函数名：";
                    string fn;
                    cin >> fn;
                    MathFunc Math = (MathFunc)GetProcAddress(hModule, fn.c_str());
                    if (Math == NULL)
                    {
                        cout << red << "找不到函数：" << reset << fn << ' ' << red << "错误代码：" << yellow << GetLastError() << reset << endl;
                        cout << "正在释放DLL..." << endl;
                        FreeLibrary(hModule);
                        continue;
                    }
                    int aa, b;
                    cout << green << "DLL文件已全部加载完成！" << reset << "请输入两个整数：";
                    wcin >> aa >> b;
                    int result = Math(aa, b);
                    cout << "结果:" << result << endl;
                    FreeLibrary(hModule);
                    cout << green << "计算完成！DLL文件已释放！";
                    system("pause");
                    cout << reset;
                    system("cls");
                }
                if (a == 372)
                    break;
            }
            continue;
        }
    }
    system("pause");
    return 0;
}