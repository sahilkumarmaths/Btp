clear;
load data1.txt
figure;
x = data1(1:20,2);
z = plot(x,data1(1:20,5),x,data1(1:20,6),x,data1(1:20,7),x,data1(1:20,8),x,data1(1:20,9));
title("Variation of entropy of binding with registers");
xlabel("Registers");
ylabel("Entropy");
legend("Initial Value",	"Random Value",	"Left Right Value",	"Center Center Value","Blossom Value",'location', 'east');
set (z,"linewidth", 2) ;
axis([5 110 0 1800]);
print -deps -color data1.eps

clear;
load data2.txt
figure;
x = data2(1:20,3);
z = plot(x,data2(1:20,5),x,data2(1:20,6),x,data2(1:20,7),x,data2(1:20,8),x,data2(1:20,9));
title("Variation of entropy of binding with phases");
xlabel("Phases");
ylabel("Entropy");
legend("Initial Value",	"Random Value",	"Left Right Value",	"Center Center Value","Blossom Value",'location', 'east');
set (z,"linewidth", 2) ;
axis([0 45 0 1800]);
print -deps -color data2.eps

clear;
load data3.txt
figure;
x = data3(1:20,4);
z = plot(x,data3(1:20,5),x,data3(1:20,6),x,data3(1:20,7),x,data3(1:20,8),x,data3(1:20,9));
title("Variation of entropy of binding with applications");
xlabel("Applications");
ylabel("Entropy");
legend("Initial Value",	"Random Value",	"Left Right Value",	"Center Center Value","Blossom Value",'location', 'east');
set (z,"linewidth", 2) ;
axis([2 25 0 600]);
print -deps -color data3.eps



