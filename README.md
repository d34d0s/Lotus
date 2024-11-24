![banner3x](https://github.com/user-attachments/assets/fdc5a337-8fd8-4dbb-a4f6-b53edd92c81c)

[![GitHub Releases Downloads](https://img.shields.io/github/downloads/F4R4W4Y/Lotus/total)](https://github.com/F4R4W4Y/Lotus/releases)
[![GitHub Stars](https://img.shields.io/github/stars/F4R4W4Y/Lotus?style=flat&label=stars)](https://github.com/F4R4W4Y/Lotus/stargazers)
[![GitHub commits since tagged version](https://img.shields.io/github/commits-since/F4R4W4Y/Lotus/Lotus.1.0.2024)](https://github.com/F4R4W4Y/Lotus/commits/master)
[![License](https://img.shields.io/badge/license-apache%2Flibpng-green.svg)](LICENSE)

#### Relevant Links

[  [Official Wiki](https://github.com/F4R4W4Y/Lotus/wiki) | [API Documentation](https://github.com/F4R4W4Y/Lotus/wiki/Lotus-API-Docs) | [Lotus Examples](https://github.com/F4R4W4Y/Lotus/tree/refactor_01/examples) ]
  
[ [Official Discord](https://discord.gg/e43PDC45wu) | [Official Reddit](https://www.reddit.com/r/Lotus/) | [Lotus Discussions](https://github.com/F4R4W4Y/Lotus/discussions) | [Lotus FAQ](https://github.com/F4R4W4Y/Lotus/wiki/Lotus-FAQ) ]

</br>


## Building Engine Source

1. **Clone the repository**:
    ```bash
    git clone https://github.com/d34d0s/Lotus.git
    cd Lotus
    ```

2. **Compile the engine**:
    For Windows, you can use `gcc` to build the engine:
    ```bash
    gcc -c lotus.core/*.c -Ipath_to_lotus_vendors -Ipath_to_lotus_includes -DLOTUS_EXPORT -o lotus.core/bin/*.o
    gcc -shared lotus.core/bin/*.o -lopengl32 -lgdi32 -o lotus.core/bin/Lotus.dll
    ```

3. **Install compiled binaries**:
    Move the compiled binaries into your project's `lib` and `bin` directories:
    ```bash
    cp lotus.core/bin/*.dll your_project/bin/
    ```
    ```bash
    cp vendor/bin/*.dll your_project/bin/
    ```

## Building Projects/Mods

1. Navigate to your project's source directory.
2. Compile your mod:
    ```bash
    gcc my_project.c -Ipath_to_lotus_includes -lLotus -o my_project.exe
    ```

</br>

<h2> 🪷 Lotus' Contributors 🪷 </h2>

<a href="https://github.com/F4R4W4Y/Lotus/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=F4R4W4Y/Lotus&max=500&columns=20&anon=1" />
</a>

</br>

<h2> 🪷 License 🪷 </h2>

Lotus is licensed under the Apache 2.0 license.

