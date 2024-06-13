<div align="center">
	<h1>🐬So Long</h1>
  "Long ago in a distant land, I, Aku, the shapeshifting master of darkness, unleashed an unspeakable evil.
  But a foolish samurai warrior wielding a magic sword stepped forth to oppose me. Before the final blow was struck, 
  I tore open a portal in time and flung him into the future where my evil is law. 
  Now the fool seeks to return to the past and undo the future that is Aku."
  <br>   <br>

  <img src="https://raw.githubusercontent.com/fbkeskin/System-Programming-2024/master/so_long_gif-ezgif.com-video-to-gif-converter%20(2).gif?token=GHSAT0AAAAAACF7SLY62H5LXGCANYLLKKLMZTLL6FA"/>
  
  <p align="center">
	<h4>And thanks for all the fish!<br>
  </p></h4>
  <p align="center">
    <i>Bu proje, küçük bir 2D oyundur. Amacı textures, sprites ve diğer bazı temel oyun öğeleriyle çalışmanızı sağlamaktır.
</i>
  </p>
  <br />
	<img src="https://img.shields.io/badge/norminette-passing-success"/>
	<a href="https://developer.apple.com/library/archive/documentation/Performance/Conceptual/ManagingMemory/Articles/FindingLeaks.html"><img src="https://img.shields.io/badge/leaks-none-success" /></a>
	<img src="https://img.shields.io/badge/-100%2F125-success?logo=42&logoColor=fff" />
</div>

## 📝Usage
1. Repo'yu clone'layın: 

```bash
git clone linkk
```

2. Makefile'ı kullanarak source kodu derleyin:
> Unutmayın, mevcut MLX library yalnızca Mac machine'lerde çalışmaktadır.
```bash
make
```
> 1 executable file oluşmaktadır: `so_long`.

3. Oynamak istediğiniz map'i argüman olarak girin ve `so_long` binary dosyasını execute ederek programı başlatın:
> Projenin kök dizininde map_files klasörü altında yer alan map'lerden birini tercih edebilirsiniz.
```shell
$>./so_long map_files/42big.ber
movement: 1
movement: 2
movement: 3
movement: 4
movement: 5
movement: 6
.
.
.
movement: 175
movement: 176
movement: 177
###   YOU WON THE GAME TOTAL 177 STEPS!   ###

$>./so_long map_files/mult_exit.ber
Error: Error: number of components is incorrect

$>./so_long gün "uzaklarda bir yerlerde güneşler doğuyor.ber" 
Error: not ber file

$>./so_long gün dönence dönence
Error: 2 arguments must be entered!
```

> Program, bilgisayarınızda bir window açarak oyun arayüzünüz ile etkileşime geçmenizi sağlar. Amaç, tüm collectible nesneleri toplayarak exit'e ulaşmaktır. 

4. Farklı map files ile çalışmak için 3. adımı tekrarlayın.


## 📚MLX
MinilibX, öğrenciler için tasarlanmış, yeni başlayanlara uygun, C dilinde basit bir X-Window programlama API'sidir.<br>

Useful links:
* [Harm Smits - MiniLibX](https://harm-smits.github.io/42docs/libs/minilibx)
* [MiniLibX](https://github.com/42Paris/minilibx-linux)
* [Laura&Simon Gitbook](https://42-cursus.gitbook.io/guide/minilibx)

Linux machine için mlx include etmek: [For Linux](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html#compilation-on-linux)


## 🎮CONTROLS
|KEYBOARD|ACTION|
|---|---|
|`W`, `↑`|Move up|
|`S`, `↓`|Move down|
|`A`, `←`|Move left|
|`D`, `→`|Move right|
|`ESC`, `❌`|Close the game window|




