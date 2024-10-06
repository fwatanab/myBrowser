#include <Network.hpp>
#include <curl/curl.h>
#include <iostream>

Network::Network() {
	// libcurlのグローバル初期化
	curl_global_init(CURL_GLOBAL_DEFAULT);
}

Network::~Network() {
	// libcurlのグローバルクリーンアップ
	curl_global_cleanup();
}

size_t	WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userData) {
	size_t	totalSize = size * nmemb;
	userData->append((char*)contents, totalSize);
	return totalSize;
}

std::string	Network::fetchPage(const std::string& url) {
	// curlのセットアップ
	CURL*		curl;
	CURLcode	res;
	std::string	readBuffer;

	// curlセッションの初期化
	curl= curl_easy_init();
	if (!curl) {
		std::cerr << "Failed to initialize CURL session!" << std::endl;
		return "";
}

	if (curl) {
		// リクエストのURLを設定
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

		// SSL証明書の有効性を確認
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
		// サーバーのホスト名を確認
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

		// レスポンスのコールバック
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		// 書き込みバッファを指定
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		// リクエストを実行
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
		}

		// curlセッションをクリーンアップ
		curl_easy_cleanup(curl);
	}

	// 取得したHTMLデータを返す
	return readBuffer;
}


// テストコード
//int	main() {
//	Network network;
//	std::string url = "https://www.example.com";
//	std::string pageContent = network.fetchPage(url);
//	if (!pageContent.empty()) {
//		std::cout << "Fetched page content: " << std::endl;
//		std::cout << pageContent << std::endl;
//	} else {
//		std::cerr << "Failed to fetch page content!" << std::endl;
//	}
//	return 0;
//}
