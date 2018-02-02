
if ~exist('s','var')
    s=serial('/dev/ttyUSB0');
    set(s,'BaudRate',9600);
end

if s.status(1)=='c'
    fopen(s);
end
pause(3)

x = [0 0 2 0.5];
y = [2 3 1 4];
z = [0 0 0 5];
r = 5;

z(1) = z(4) + sqrt(r^2 - (x(1) - x(4))^2 - (y(1) - y(4))^2);
z(2) = z(4) + sqrt(r^2 - (x(2) - x(4))^2 - (y(2) - y(4))^2);
z(3) = z(4) + sqrt(r^2 - (x(3) - x(4))^2 - (y(3) - y(4))^2);


%kolumny
col1=line([x(1) x(1)], [y(1) y(1)], [0 30]);
col2=line([x(2) x(2)], [y(2) y(2)], [0 30]);
col3=line([x(3) x(3)], [y(3) y(3)], [0 30]);
%ramiona
arm1=line([x(1) x(4)], [y(1) y(4)], [z(1) z(4)]);
arm2=line([x(2) x(4)], [y(2) y(4)], [z(2) z(4)]);
arm3=line([x(3) x(4)], [y(3) y(4)], [z(3) z(4)]);


view(75,45);
axis equal;
hold on;
pause(5);

for t = 0:0.1:20
    
    x(4) = sin(t) + 2;
    y(4) = cos(t) + 3.5;
    z(4) = 0.5 * t;
    
    z(1) = z(4) + sqrt(r^2 - (x(1) - x(4))^2 - (y(1) - y(4))^2);
    z(2) = z(4) + sqrt(r^2 - (x(2) - x(4))^2 - (y(2) - y(4))^2);
    z(3) = z(4) + sqrt(r^2 - (x(3) - x(4))^2 - (y(3) - y(4))^2);
    
    if t>0
        
        step1 = zo(1)-z(1);
        step2 = zo(2)-z(2);
        step3 = zo(3)-z(3);
        text = ['x' num2str(round(step1*10000)) 'y' num2str(round(step2*10000)) 'z' num2str(round(step3*10000))];
        fprintf(s,text)
        
        while s.BytesAvailable<1
        end
        while s.BytesAvailable>0
            fscanf(s)
        end
    end
    
    set(arm1, 'XData', [x(1) x(4)], 'YData', [y(1) y(4)], 'ZData', [z(1) z(4)]);
    set(arm2, 'XData', [x(2) x(4)], 'YData', [y(2) y(4)], 'ZData', [z(2) z(4)]);
    set(arm3, 'XData', [x(3) x(4)], 'YData', [y(3) y(4)], 'ZData', [z(3) z(4)]);
    axis equal
    
    zo(1) = z(1);
    zo(2) = z(2);
    zo(3) = z(3);
end