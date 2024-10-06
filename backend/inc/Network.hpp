#ifndef NETWORK_HPP
#define NETWORK_HPP

#include <string>

class	Network {
	public:
		Network();
		~Network();

		// 指定されたURLからHTMLを取得する関数
		std::string	fetchPage(const std::string& url);

	private:
		// 必要ならば、内部的にcurlの設定やリソース管理に使用するメンバ変数を追加
		// 例えば、CURLオブジェクトの初期化などに使う場合
};

#endif
