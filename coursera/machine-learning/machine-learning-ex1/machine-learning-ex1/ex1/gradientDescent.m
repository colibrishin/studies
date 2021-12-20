function [theta, J_history] = gradientDescent(X, y, theta, alpha, num_iters)
%GRADIENTDESCENT Performs gradient descent to learn theta
%   theta = GRADIENTDESCENT(X, y, theta, alpha, num_iters) updates theta by 
%   taking num_iters gradient steps with learning rate alpha

% Initialize some useful values
m = length(y); % number of training examples
J_history = zeros(num_iters, 1);

hys_w_y = zeros(length(theta), 1);
hys = zeros(m, 1);

for iter = 1:num_iters

	for i = 1:m
		hys = theta(1) + theta(2) * X(:,2:2);
	end
	
	hys = hys - y;
	sig = X(:,1:2) .* hys;
	
	for i = 1:length(theta)
		theta(i) = theta(i) - (alpha * (1 / m)) * sum(sig(:,i:i));
	end
	
	J_history(iter) = computeCost(X, y, theta);

end

end
