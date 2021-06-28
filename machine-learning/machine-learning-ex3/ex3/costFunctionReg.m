function [J, grad] = costFunctionReg(theta, X, y, lambda)
%COSTFUNCTIONREG Compute cost and gradient for logistic regression with regularization
%   J = COSTFUNCTIONREG(theta, X, y, lambda) computes the cost of using
%   theta as the parameter for regularized logistic regression and the
%   gradient of the cost w.r.t. to the parameters. 

% Initialize some useful values
m = length(y); % number of training examples

% You need to return the following variables correctly 
J = 0;
grad = zeros(size(theta));

sigtheta = 0;
hy = 0;
arrhy = zeros(m, 1);

for i=1:m
	hy = sigmoid(X(i:i,:) * theta);
	total = (-(y(i)) * log(hy)) - ((1 - y(i)) * log(1-hy));
	J = J + total;
end

J = (1 / m) * J;

for i=2:length(theta)
	sigtheta = sigtheta + theta(i)^2;
end
sigtheta

J = J + lambda / (2 * m) * sigtheta;

for j=1:length(theta)
	for i=1:m
		arrhy(i, j) = ((sigmoid(X(i:i,:) * theta)) - y(i)) * X(i:i, j:j);
	end
end

for i=1:length(theta)
	 grad(i) = (1 / m) * (sum(arrhy))(i);
end

for i=2:length(theta)
	grad(i) = grad(i) + (lambda / m) * theta(i);
end

end


% ====================== YOUR CODE HERE ======================
% Instructions: Compute the cost of a particular choice of theta.
%               You should set J to the cost.
%               Compute the partial derivatives and set grad to the partial
%               derivatives of the cost w.r.t. each parameter in theta






% =============================================================