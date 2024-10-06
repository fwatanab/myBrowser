#include <Node.hpp>

Node::Node(const std::string& tagName) : tagName(tagName), content("") {}

Node::~Node() {}

void	Node::addNode(std::shared_ptr<Node> child) {
	children.push_back(child);
}

void	Node::setContent(const std::string& text) {
	content = text;
}

std::string	Node::getTagName() const {
	return tagName;
}

std::string	Node::getContent() const {
	return content;
}

const std::vector<std::shared_ptr<Node>>&	Node::getChildren() const {
	return children;
}
