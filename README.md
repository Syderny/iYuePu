# iYuePu
# CppProjectX
This is a project designed for composing music with your numbered music notation.  
Click [Here](#001) to a Chinese Version.   

### project name:
iYuePu.
### Project Description:

> "Enter the notation, tap Play, and leave the rest to us."

This project is to serve people who don't have instruments or play instruments. All you need is a piece of music and a computer with a sound. Just enter any score you want to enter, run the program, and you can play it with your computer. This wonderful and beautiful melody. Music scores contain tones, basic notes, and extensions, lift notes, and more.
#### Example:
Enter:
_A4 _B4 C5· _B4 C5 E5 B4 - -
_E4 _E4 A4· _G4 A4 C5 G4 - -
E4 F4· _E4 _F4 C5· E4 -
_C5 _C5 _C5 B4· _F4# F4# B4 B4 - -

A0 and B0 represent the two rightmost white keys on the piano keyboard, which are also the lowest sounds of La and Ti. The sound is higher than the ones: A1, B1, A2, B2, and so on. F4# and other keys with # are black keys in the piano.
The underline indicates that the tone is a semitone, the postpoint indicates that the tone is extended by half, and the delay line "-" indicates the time value of the tone. The longer the delay line, the longer the note playback time.

#### How to operate
You can use the mouse or keyboard to complete the input of the entire score.
##### Mouse operation
Open the interface, the piano 88 keys will be presented in front of you. With just a click of the mouse, the music will fly out of the computer between your fingers. You need to “pause”, “lift half-shoot” and so on, just click on the upper right. Corner button.
##### Keyboard operation
Entering the score you create directly is as easy as creating on the piano!

Project realization process:
1. Audio interception, stored as a number of vowels: the instrument is initially set to piano, guitar, harmonica, and input scores.
2, audio debugging test pitch, unified audio format for synthesis processing.
3. Project interface design:
Please check the [项目简介.doc] file.
4. Analysis of the input part of the score: The score of the input part is processed by the character string. By processing the input score, the specified unit audio is extracted to the file, and then played according to the set number of beats per minute, which can satisfy some users. The need for double speed playback.

Division of labor:
A (initiator):
Coordinate the overall work, process and test the audio and source code, and design the beautification project interface.
B: Mainly responsible for collecting audio production vowels. It is estimated that 60 vowel files need to be processed and tested, and the workload is large.
C, D, E: Mainly responsible for processing the input score data according to the preset file format at the time of B collection and simulating the extraction of the corresponding audio file to assist B to complete the audio collection test. After the collection is completed, debug the play track and design the beautification project graphical interface. 

-------

[项目介绍.pptx](iyuepu.pptx)

[项目演示.mp4](demo_video.mp4)

[项目代码.zip](codes.zip)

[Here](#001)
### 项目名称：
i悦谱。  
### 项目简介：

> "输入简谱，轻点Play，剩下的交给我们。"

本项目是为了服务手边没有乐器或者不会演奏乐器的人，您需要的只是一段乐谱和一个带有音响的一台计算机，只要输入您想输入的任意乐谱，运行该程序，即可用计算机来演奏这段美妙动听的旋律。乐谱输入含调式、基本音符以及延长、升降音符等等。  
#### 示例：  
输入：  
_A4 _B4 C5· _B4 C5 E5 B4  -  -
_E4 _E4 A4· _G4 A4 C5 G4  -  -
E4 F4· _E4 _F4 C5· E4  -
_C5 _C5 _C5 B4· _F4# F4# B4 B4  -  -  

A0、B0代表的是钢琴键盘上最右边的两个白色琴键，也是La、Ti的最低音，音高于其有：A1、B1、A2、B2···以此类推。F4#等带有#的键为钢琴中的黑键。  
前置下划线表示这个音是半音，后置点号表示延长半个音，延时线“-”表示这个音的时值，延时线越长，音符播放时间越长。

#### 操作方法
您可以用鼠标或键盘完成整个乐谱的输入。
##### 鼠标操作
打开界面，钢琴88个键便呈现在您的面前，您只要轻点鼠标，乐符便在您的指间从计算机中飞舞出来，需要“停顿”“升降半拍”等操作，只需点击右上角的按钮。
##### 键盘操作
直接输入您创作的乐谱，就像在钢琴上创作一样简单！

项目实现过程：
1、音频截取，储存为若干元音：乐器初定为钢琴、吉他、口琴，输入乐谱。  
2、音频调试测试音准，统一音频格式以便于合成处理。  
3、项目界面设计：    
请查看[项目简介.doc]文件  
4、乐谱输入部分的分析：输入部分的乐谱通过字符串进行处理，通过对输入乐谱的处理，定向到文件提取指定的单元音频，再按照设定的每分钟拍数进行播放，可以满足部分用户倍速播放的需求。  

人员分工：  
A（发起者）:  
协调整体工作，处理并测试音频与源代码，设计美化项目界面。    
B：主要负责收集音频制作元音，初步估计有60个元音文件需要处理测试，工作量较大。  
C、D、E：主要负责，在B收集的时间根据预先设定好的文件格式处理输入乐谱数据并模拟提取相应的音频文件，协助B完成音频收集测试。在收集完毕之后调试播放曲目，设计美化项目图形界面。  
