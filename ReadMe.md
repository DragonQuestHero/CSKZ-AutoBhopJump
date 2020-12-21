# CSKZ-AutoBhopJump


### 由于游戏(单指CSOL)的反外挂保护限制了winhook GetAsyncKeyState等获取按键消息


### 同时也屏蔽掉了mouse_move sendinput R3层的消息 所以使用驱动来发送和监听按键消息


#### 监听和发送均利用了KeyboardClassServiceCallback 支持win7-win10 详情:http://blog.wonderkun.cc/2019/04/02/Hook%20KeyboardClassServiceCallback%20%E5%AE%9E%E7%8E%B0%E5%86%85%E6%A0%B8%E6%80%81%E6%8C%89%E9%94%AE%E8%AE%B0%E5%BD%95%E5%92%8C%E6%A8%A1%E6%8B%9F/


### BhopJump

#### 支持CS1.6 CSOL(国服 韩服 steam国际服) CSGO

#### 半联动模式:判断当前鼠标位置来判断发送左或右键代码实现空中转向加速 同时不停的发送滚轮跳来实现BJ

#### 在FPS稳定的情况下 可以手动空中最多加速4次 空速可以稳定在320左右

#### 超过4次空中加速脚本就跟不上了

<h1 align="center">
	<img src="BhopJump.gif" alt="">
	<br>
	<br>
</h1>



### MCJ

#### MCJ外部脚本可以直接超越人类极限到达接近USP2倍地速的可能 最高一次调教地速直接上480

#### MCJ是最难调的部分 如果想保持正常行走方向 地速大概在270以上320以下

<h1 align="center">
	<img src="MCJ.gif" alt="">
	<br>
	<br>
</h1>



### AutoBhopJump

#### 全自动模式:BJ+瞎晃鼠标即可

#### FPS稳定的情况下空速可以到达320左右

<h1 align="center">
	<img src="AutoBhopJump.gif" alt="">
	<br>
	<br>
</h1>



### LongJump

#### 默认空中4次加速

#### 265地速直接带你上240的板子

#### 同步率基本是100% 98%同步率一般只有骨灰玩家了

<h1 align="center">
	<img src="LongJump.gif" alt="">
	<br>
	<br>
</h1>


### 海皇跳

#### 海皇右键爆炸有延迟 左右一起按又按不出来了 

<h1 align="center">
	<img src="HaiHuang.gif" alt="">
	<br>
	<br>
</h1>
