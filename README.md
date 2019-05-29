# Prim_In_C
프림(Prim)알고리즘을 이용해서 최소신장트리(MST)를 만들어보자.

 <h3>입력</h3>
 <p>입력으로는 파일로서 데이터를 입력 받게 만들었습니다. "data.txt"에는 아래의 그림과 같은 그래프의 데이터가 들어있습니다.</p>
 <hr>
<img src = "http://cslab2.kku.ac.kr/~201721210/prim_1.JPG" width = "674px" height = "433px"><br>
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
  <li>첫 번재 줄의 <pre>11 7</pre>은 각각 그래프의 <b>전체 간선의 개수</b>와 <b>전체 노드의 개수</b>를 나타냅니다.</li><br>
  <li>그 뒤에 나오는 <pre>1 7 12</pre>의 형식은 각각 <b>노드A</b>,&nbsp;&nbsp;<b>노드B</b>,&nbsp;&nbsp;<b>노드A와 노드B의 가중치 값</b>의 형식입니다.</li><br>
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
   </li><br>
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
 
 
 
