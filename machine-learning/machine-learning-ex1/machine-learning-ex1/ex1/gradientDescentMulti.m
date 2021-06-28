function [theta, J_history] = gradientDescentMulti(X, y, theta, alpha, num_iters)
%GRADIENTDESCENTMULTI Performs gradient descent to learn theta
%   theta = GRADIENTDESCENTMULTI(x, y, theta, alpha, num_iters) updates theta by
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

for iter = 1:num_iters

	for i = 1:m
		hys = theta(1) + theta(2) * X(:,2:2) + theta(3) * X(:,3:3);
	end
	
	hys = hys - y;
	sig = X(:,1:3) .* hys;
	
	for i = 1:length(theta)
		theta(i) = theta(i) - (alpha * (1 / m)) * sum(sig(:,i:i));
	end
	
    J_history(iter) = computeCostMulti(X, y, theta);
end
