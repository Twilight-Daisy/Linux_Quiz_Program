# Linux_Quiz_Program
리눅스 쉘 스크립트 문법에 관련된 문제들을 사용자가 맞추는 프로그램입니다.  
리눅스 환경에서 작동하며, 터미널 간의 대전 방식이 적용되었습니다.
<br><br>

# 설치 및 컴파일 방법
1. source 디렉토리를 다운받습니다.
2. 아래 명령어를 통해 컴파일을 진행하여 실행파일 2개를 생성합니다.
```
g++ Exam.cpp UserData.cpp UI.cpp Client.cpp -o client
g++ Exam.cpp UserData.cpp Server.cpp -o server
```

# 실행 방법
1. 사용할 터미널을 띄웁니다.
	* server 실행 터미널
	* 프로그램 실행 터미널(kill 명령어 사용)
	* client 실행 터미널(최대 5개의 터미널 지원)
<br><br>

2. server를 실행합니다.
```
./server
```
<img src="https://user-images.githubusercontent.com/65950455/101773964-d3a1d700-3b30-11eb-8fc3-7a344eb38a28.PNG"></img>
<br><br>

3. client를 실행하여 닉네임을 입력합니다.  
(최대 5개의 터미널을 지원하나 예시에서는 2개의 터미널을 사용합니다.)
```
./client
```
<img src="https://user-images.githubusercontent.com/65950455/101772342-976d7700-3b2e-11eb-9ef2-10c6ebd33949.PNG"></img>
<img src="https://user-images.githubusercontent.com/65950455/101772355-99cfd100-3b2e-11eb-896e-022d2aa657c9.PNG"></img>
<br><br>

4. kill 명령어로 프로그램을 실행합니다.
```
kill -SIGUSR1 [Server pid]
```
<img src="https://user-images.githubusercontent.com/65950455/101774359-56c32d00-3b31-11eb-8c0b-32bf91fead03.PNG"></img>
- 클라이언트 변경 화면  
<img src="https://user-images.githubusercontent.com/65950455/101774657-c0433b80-3b31-11eb-9c49-19e2c3976399.PNG"></img>
<br><br>

5. client에 문제의 답을 입력합니다.
각 client에서 맞춘 정답의 갯수를 하단에 표시해줍니다.  
총 27문항이 준비되어있으며, 모든 문제가 끝났을 경우 server는 자동 종료합니다.  
server에서 문제, 정답을 확인할 수 있습니다.  
<img src="https://user-images.githubusercontent.com/65950455/101775330-a6562880-3b32-11eb-9129-4866d0c46f4d.PNG"></img>
<br><br>

6. 종료 시 client, server의 터미널에 Ctrl + C를 입력합니다.

<br><br>

* Q. server에서 Wait Client가 무한 출력되는데 어떻게 해야 하나요?  
프로그램의 비정상 시작/종료(ex - server가 아닌 client를 먼저 실행시켰을 경우)에 의해 발생하는 오류입니다.  
ipcs 명령어로 이미 생성되어 있는 Message Queue와 Shared Memory를 확인한 후
ipcrm으로 제거한 후 실행하면 정상 작동됩니다.
```
ipcs	// IPC 자원 정보 출력
ipcrm -q [생성된 mspid]
ipcrm -m [생성된 shmid]
```
<img src="https://user-images.githubusercontent.com/65950455/101779541-c2f55f00-3b38-11eb-9b21-a803869d7e54.PNG"></img>
