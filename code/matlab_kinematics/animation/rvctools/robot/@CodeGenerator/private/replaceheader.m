%CODEGENERATOR.REPLACEHEADER Replace autogenerated function headers by Toolbox-headers.
%
% CGen.replaceheader(HSTRUCT,FILENAME)
% HSTRUCT is the struct defining the contents of the header.
% FILENAME is the relative or full path to the file that has an autogenerated
% header to be replaced.
%
% Notes::
% The MatLab built-in function "matlabFunction" generates a standard
% header stub of 3 lines. This header is extended by the common
% toolbox-header. The contents of the header are coded in a struct that is
% the first input parameter and has the following self-explaining fields:
%
% Fieldname              Datatype
% - funName              'string'
% - shortDescription     'string'
% - detailedDescription  {'line1','line2',...}
% - inputs               {'input1: description','input2: description',...}
% - outputs              {'output1: description','output2: description',...}
% - examples             {'line1','line2',...}
% - knownBugs            {'line1','line2',...}
% - toDO                 {'line1','line2',...}
% - references           {'line1','line2',...}
% - authors              {'line1','line2',...}
% - seeAlso              {'function1','function2',...}
%
% Authors::
%  Joern Malzahn   
%  2012 RST, Technische Universitaet Dortmund, Germany
%  http://www.rst.e-technik.tu-dortmund.de    
%
% See also matlabFunction, CodeGenerator.constructheaderstring.

% Copyright (C) 1993-2012, by Peter I. Corke
% Copyright (C) 2012-2013, by Joern Malzahn
%
% This file is part of The Robotics Toolbox for Matlab (RTB).
%
% RTB is free software: you can redistribute it and/or modify
% it under the terms of the GNU Lesser General Public License as published by
% the Free Software Foundation, either version 3 of the License, or
% (at your option) any later version.
%
% RTB is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
%
% You should have received a copy of the GNU Leser General Public License
% along with RTB.  If not, see <http://www.gnu.org/licenses/>.
%
% http://www.petercorke.com
%
% The code generation module emerged during the work on a project funded by
% the German Research Foundation (DFG, BE1569/7-1). The authors gratefully 
% acknowledge the financial support.
 
function [] = replaceheader(CGen,hStruct,fileName)

%% Get the first three lines of the original file
threeLines = cell(1,3); % innitialize storage cell
fid = fopen(fileName,'r');  % open the file

threeLines{1} = fgetl(fid); % read the three lines
threeLines{2} = fgetl(fid);
threeLines{3} = fgetl(fid);

fclose(fid);                 % close the file

%% Delete old header
CGen.ffindreplace(fileName,threeLines{1},''); % Erase first line
CGen.ffindreplace(fileName,threeLines{2},''); % Erase second line
CGen.ffindreplace(fileName,threeLines{3},''); % Erase third line

%% Insert new header
hFString = CGen.constructheaderstring(hStruct);
CGen.finsertfront(fileName, sprintf([threeLines{1},'\n%s\n%s'],hFString,CGen.getpibugfixstring));


end