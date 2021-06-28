function [J, grad] = costFunction(theta, X, y)
%COSTFUNCTION Compute cost and gradient for logistic regression
%   J = COSTFUNCTION(theta, X, y) computes the cost of using theta as the
%   parameter for logistic regression and the gradient of the cost
%   w.r.t. to the parameters.

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

hy = 0;
arrhy = zeros(m, 1);

for i=1:m
	hy = sigmoid(X(i:i,:) * theta);
	total = (-(y(i)) * log(hy)) - ((1 - y(i)) * log(1-hy));
	J = J + total;
end

J = (1 / m) * J;

for j=1:length(theta)
	for i=1:m
		arrhy(i, j) = ((sigmoid(X(i:i,:) * theta)) - y(i)) * X(i:i, j:j);
	end
end

for i=1:length(theta)
	 grad(i) = (1 / m) * (sum(arrhy))(i);
end

end
