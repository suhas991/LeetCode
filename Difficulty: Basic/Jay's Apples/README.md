<h2><a href="https://www.geeksforgeeks.org/problems/jays-apples2724/1?page=1&category=set&sortBy=submissions">Jay's Apples</a></h2><h3>Difficulty Level : Difficulty: Basic</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">One day Jay, on getting his first salary, decides to distribute apples among the poverty-stricken persons. He gave each person 1kg of apples. People are coming in a queue&nbsp;and he makes sure that he gives every person 1 kg of apples only once. Every person is identified by a specific integer.</span></p>
<p><span style="font-size: 18px;">Given the queue followed by an array, denoting the persons in that queue, find the minimum kilograms of apples Jay will have to distribute.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 1, 1, 1, 1]
<strong>Output:</strong> 1
<strong>Explanation: </strong>For test case 1, the same person (identified by the integer '1' comes again and again in the queue, but Jay will not give him apples again and again. He gave him apples only once so minimum kg's of apples here required-1kg)
</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> arr[] = [1, 2, 3, 1, 2]<strong>
Output:</strong>  3</span></pre>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong> O(n).</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ arr.size() ≤ 10<sup>6</sup><br>1 ≤ arr[i] ≤ 10<sup>6</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>set</code>&nbsp;<code>Arrays</code>&nbsp;<code>STL</code>&nbsp;<code>Data Structures</code>&nbsp;