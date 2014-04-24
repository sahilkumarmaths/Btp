1;
% with cores
clear;
load center_reg.txt
figure;
data = center_reg 

x = data(1:20,2);
z = plot(x,data(1:20,6),"g*-",x,data(1:20,7),"bo-",x,data(1:20,8),"md-",x,data(1:20,9),"cp-",x,data(1:20,10),"rx-");

set(gca,'fontsize',24);
title("Variation of parameters with Cores");
xlabel("Cores");
ylabel("Entropy");
set(gca,'fontsize',18);
legend(strcat('\alpha',"=0.00,",'\beta','=1.00'),strcat('\alpha',"=0.25,",'\beta','=0.75'),strcat('\alpha',"=0.50,",'\beta','=0.50'),strcat('\alpha',"=0.75,",'\beta','=0.25'),strcat('\alpha',"=1.00,",'\beta','=0.00'),'location', 'south');
set (z,"linewidth", 3) ;
axis([5 110 0 1800]);
print -deps -color center_reg.eps

% with phases
clear;
load center_phase.txt
figure;
data = center_phase 

x = data(1:20,3);
z = plot(x,data(1:20,6),"g*-",x,data(1:20,7),"bo-",x,data(1:20,8),"md-",x,data(1:20,9),"cp-",x,data(1:20,10),"rx-");

set(gca,'fontsize',24);
title("Variation of parameters with Phases");
xlabel("Phases");
ylabel("Entropy");
set(gca,'fontsize',18);
legend(strcat('\alpha',"=0.00,",'\beta','=1.00'),strcat('\alpha',"=0.25,",'\beta','=0.75'),strcat('\alpha',"=0.50,",'\beta','=0.50'),strcat('\alpha',"=0.75,",'\beta','=0.25'),strcat('\alpha',"=1.00,",'\beta','=0.00'),'location', 'south');
set (z,"linewidth", 3) ;
axis([0 45 0 1800]);
print -deps -color center_phase.eps

% with apps
clear;
load center_app.txt
figure;
data = center_app ;

x = data(1:20,4);
z = plot(x,data(1:20,6),"g*-",x,data(1:20,7),"bo-",x,data(1:20,8),"md-",x,data(1:20,9),"cp-",x,data(1:20,10),"rx-");

set(gca,'fontsize',24);
title("Variation of parameters with Applications");
xlabel("Applications");
ylabel("Entropy");
set(gca,'fontsize',18);
legend(strcat('\alpha',"=0.00,",'\beta','=1.00'),strcat('\alpha',"=0.25,",'\beta','=0.75'),strcat('\alpha',"=0.50,",'\beta','=0.50'),strcat('\alpha',"=0.75,",'\beta','=0.25'),strcat('\alpha',"=1.00,",'\beta','=0.00'),'location', 'south');
set (z,"linewidth", 3) ;
axis([2 25 0 600]);
print -deps -color center_app.eps
