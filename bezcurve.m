%This is an Octave UDF that generates the intermediate points of a cubic Bezier Curve
%Function cubez() takes a 2x4 matrix as an input and genenerates a 2x101 matrix (p) as an output.
%The first row of the input and output matrix contains the abcissa of the coordinates and the second row contains the ordinates of the coordinates.
%The cubez() function generates 99 points in between terminal control points.
%Try the sample input a=[100, 200, 300, 400; 100, 50, 320, 100]
function p=cubez(points)
  if(size(points)==[2,4])
    p=zeros(2,101)
    bez=zeros(1,4)
    for i =0:100
      u=0.01*i
      for j = 0:3
        bez(:,j+1)=nchoosek(3,j)*power(u,j)*power(1-u,3-j)
        p(:,i+1)=p(:,i+1)+points(:,j+1).*bez(:,j+1)
      endfor
    endfor
    plot(p(1,:),p(2,:),points(1,:),points(2,:))
  else
    printf("Invalid Anguments. Argument matrix must be a 2x4")
  endif
endfunction
