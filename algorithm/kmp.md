# KMP算法理解
1. 第一位不相同，搜索词后移一位(上面为源字符串，下面为搜索词)<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/1.jpg)
2. 因为B与A不匹配，搜索词再往后移<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/2.jpg)
3. 移动直到有一个字符串与搜索词的第一个字符相同为止<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/3.jpg)
4. 接着比较字符串和搜索词的下一个字符，仍然相同<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/4.jpg)
5. 直到字符串有一个字符，与搜索词对应的字符不相同为止<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/5.jpg)
6. 这时，最自然的反应是，将搜索词整个后移一位，再从头逐个比较。这样做虽然可行，但是效率很差，因为你要把"搜索位置"移到已经比较过的位置，重比一遍。<br>
7. 一个基本事实是，当空格与D不匹配时，你其实知道前面六个字符是"ABCDAB"。KMP算法的想法是，设法利用这个已知信息，不要把"搜索位置"移回已经比较过的位置，继续把它向后移，这样就提高了效率。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/7.jpg)
8. 要做到这一点，针对搜索词，算出一张《部分匹配表》（Partial Match Table）<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/8.jpg)
9. 已知空格与D不匹配时，前面六个字符"ABCDAB"是匹配的。查表可知，最后一个匹配字符B对应的"部分匹配值"为2，因此按照下面的公式算出向后移动的位数：{移动位数 = 已匹配的字符数 - 对应的部分匹配值}。6-2=4，所以将搜索词后移4位。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/9.jpg)
10. 因为空格与Ｃ不匹配，搜索词还要继续往后移。这时，已匹配的字符数为2（"AB"），对应的"部分匹配值"为0。所以，移动位数 = 2 - 0，结果为 2，于是将搜索词向后移2位。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/10.jpg)
11. 空格与A不匹配，继续后移一位<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/11.jpg)
12. 逐位比较，直到发现C与D不匹配。于是，移动位数 = 6 - 2，继续将搜索词向后移动4位。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/12.jpg)
13. 逐位比较，直到搜索词的最后一位，发现完全匹配，于是搜索完成。如果还要继续搜索（即找出全部匹配），移动位数 = 7 - 0，再将搜索词向后移动7位，这里就不再重复了。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/13.jpg)
14. 《部分匹配表》的产生
- "前缀"和"后缀"。 "前缀"指除了最后一个字符以外，一个字符串的全部头部组合；"后缀"指除了第一个字符以外，一个字符串的全部尾部组合。<br>
![](https://github.com/sjtujw/data-structure-and-algorithm/raw/master/img/14.jpg)