# Prim_In_C
프림(Prim)알고리즘을 이용해서 최소신장트리(MST)를 만들어보자.

 <h3>입력</h3>
 <p>입력으로는 파일로서 데이터를 입력 받게 만들었습니다. "data.txt"에는 아래의 그림과 같은 그래프의 데이터가 들어있습니다.</p>
 <hr>
<img src = "http://cslab2.kku.ac.kr/~201721210/prim_1.JPG" width = "80%" height = "80%"><br>
<ol>
  <li>"data.txt"파일에 위의 그림과 같은 데이터 형식을 파일 입출력을 통해 얻을 수 있도록 텍스트 파일의 구조로 변경합니다.</li>
<pre>
10 6
0 1 3
0 3 2
0 4 4
1 3 4
1 2 1
1 5 2
2 5 1
3 4 5
3 5 7
4 5 9
</pre>
  <li>첫 번재 줄의 <pre>11 7</pre>은 각각 그래프의 <b>전체 간선의 개수</b>와 <b>전체 노드의 개수</b>를 나타냅니다.</li><br><br>
  <li>그 뒤에 나오는 <pre>1 7 12</pre>의 형식은 각각 <b>노드A</b>,&nbsp;&nbsp;<b>노드B</b>,&nbsp;&nbsp;<b>노드A와 노드B의 가중치 값</b>의 형식입니다.</li><br><br>
  <li>이 파일의 형식을 "kruskal.c"의 <pre><b>EDGE *read_graph(char *GFile, int *m, int *n);</b></pre>에서 읽도록 합니다.<br>
      <pre>
      <code>
EDGE *read_graph(char *GFile, int *m, int *n)
{
  FILE *fp;
	EDGE *elist;
	int i = 0;

	if ((fp = fopen(GFile, "r")) != NULL)
	{
    fscanf(fp, "%d%d", m, n); // total edge and vertex
		elist = (EDGE *)malloc(sizeof(EDGE) * (*m));

		while (i < *m)
		{
			fscanf(fp, "%d%d%d", &elist[i].node[0], &elist[i].node[1], &elist[i].distance);
			i++;
		}
	}
	else
	{
		perror("error : can't read file");
	}
	return elist;
}
      </code>
      </pre>
   </li><br><br><br>
    <li>사용한 라이브러리 및 매크로 상수 + 전역 변수
    
	#pragma once
	#pragma warning(disable: 4996)
	#include <stdio.h>
	#include <stdlib.h>
	#define TRUE 1
	#define FALSE 0

	//정점의 개수
	#define VERTICES 1000

	//무한대
	#define INF 100000L

	//가중치 값을 갖는 배열
	 int WeightG[VERTICES][VERTICES];

	//이미 방문한 값에 대한 배열
	 int visited[VERTICES];

	//어떠한 두 노드에 대한 최소 가중치 값을 저장하는 배열
	 int D[VERTICES];
	 
	 
	---------------------------------------------------------------------------------------------------------------------	
	1. 보통은 하나의 파일에 코드를 작성할 때외부에 알릴이유가 없으면서 또한 중복될 가능성이 있는 모든 변수와 함수에 static을 걸어준다.
	2. 함수와 변수를 나눠서 외부에 알릴 필요가 있다면 statc을 해제하고 알릴 필요가 없다면 static을 반드시 걸어줍니다.
	3. 이 코드의 경우 헤더 파일 하나와 c파일 2개로 분할 되어 있기 때문에 static을 해제하도록 작성햐였다.
	  
  </li><br><br>
  <li>코드내에서 주로 사용되는 구조체 변수<br>
  
      typedef struct EDGE
      {
        int u, v;                   // (u,v)
        int w;                      // weight
      }EDGE;
      //G=(V,E)
  </li><br><br>
  <li>사용된 함수
  <ol>
    <li>
      <b>EDGE *read_graph(char *GFile, int *m, int *n);</b><br>
      <p>입력으로 들어온 파일에 데이터를 이용해 기본적인 그래프 배열의 값을 설정하는 함수이다.</p>
    </li>
    <li>
      <b>int e_order(const void *, const void *);</b><br>
      <p>stdlib.h에 있는 qsort()함수를 쓰기 위해서는 비교함수가 필요하다. 따라서 이 함수는 비교함수로 사용된다.</p>
    </li>
    <li>
      <b>void KruskalMST(EDGE * elist, EDGE * T, int nedges, int nvertex);</b><br>
      <p>크리스컬 알로리즘을 구현한 코드의 핵심 함수. 이 함수에서 부가적으로 다른 함수들을 호출하여 BST를 생성한다.</p>
    </li>
    <li>
      <b>void set_init(int n);</b><br>
      <p>BST 생성을 위한  __parent, num 배열을 초기화 한다.</p>
    </li>
    <li>
      <b>int check_cycle(EDGE E);</b><br>
      <p>현재 Graph 배열에서 가중치가 가장 작은 선분을 가져오면 그 선분 E에 대하여 사이클이 만들어지는지 아닌지 확인한다.</p>
    </li>
    
        가져온 선분 E를 추가했을때 사이클을 만들지 않으면 E를 Tree에 추가시키고 트리의 선분 수를 증가시킨다. 만약 사이클을 만들면 선분E를 
        버린다. 이때 선분 E는 해당 코드에선 이미 퀵 소트를 통해 오름차순으로 정렬된 Graph배열에서 하나씩 가져오는 것으로 Graph 배열의 각 
        요소의 값은 [노드1{u}, 노드2{2}, 노드1와 노드2 사이의 가중치] 로 이루어져 있다. 사이클의 생성 여부는 set_find()함수를 통해 각 노드!
        과 노드2가 속해져 있는 집합의 대표 노드(루트)를 가져와 같은지 같지 않은지 비교한다. 만약 같지 않다면 두 집합을 합치기 위해 set_union()
        함수를 호출한다.
    
   <li>
   
 </ol>
 <br>
 <h3>출력결과</h3>
 <p>출력 결과로서 처음 파일의 데이터를 읽고 변수에 저장한 값을 출력하고, 퀵 소트(quick sort)이후 오름차순으로 정렬된 값으로 정렬된 값들을 출력한 뒤에 마지막으로 최소신장트리(BST)의 가중치의 합(sum)을 출력해준다.</p>
 <hr>
 <img src = "http://cslab2.kku.ac.kr/~201721210/output.jpg" width = "373px" height = "442px"><br>
 
 <br>
 <br>
 
 <h3>참고</h3>
 <ul>
  <li><a href = "https://www.youtube.com/watch?v=AMByrd53PHM&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=18">합집합 찾기(Union-Find)   </a></li>
  <li><a href = "https://www.youtube.com/watch?v=LQ3JHknGy8c&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=19">크루스칼 알고리즘(Kruskal Algorithm)</a></li>
 </ul>
 
 
 
