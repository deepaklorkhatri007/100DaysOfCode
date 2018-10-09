x = y = linspace(-8, 8, 41);
[xx, yy] = meshgrid(x, y);
r = sqrt(xx.^2 + yy.^2) + eps;
z = sin(r) ./ r;
mesh(x, y, z);
xlabel("x");
ylabel("y");
zlabel("z");
title("3-D Sombrero plot"); 