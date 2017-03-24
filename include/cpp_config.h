/* Copyright(c). All Rights Reserved
 * Author: Xu Zhenqi
 * Email: xuzhenqi@bytedance.com
 */

#ifndef CPP_CONFIG_H_
#define CPP_CONFIG_H_

#include <string>
#include <unordered_map>
#include <fstream>

using std::string;

class Config {
 public:
  static Config& Instance() {
    static Config config;
    return config;
  }

  void LoadConfig(const string& filename) {
    std::ifstream in(filename);
    string item, value;
    while(in >> item >> value) {
      data_[item] = value;
    }
  }
  bool Parse(const string& item, string* value) {
    bool out = ValidItem(item);
    if (out) *value = data_[item];
    return out;
  }
  bool Parse(const string& item, int* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stoi(data_[item]);
    return out;
  }
  bool Parse(const string& item, long* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stol(data_[item]);
    return out;
  }
  bool Parse(const string& item, long long* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stoll(data_[item]);
    return out;
  }
  bool Parse(const string& item, float* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stof(data_[item]);
    return out;
  }
  bool Parse(const string& item, double* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stod(data_[item]);
    return out;
  }
  bool Parse(const string& item, long double* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stold(data_[item]);
    return out;
  }
  bool Parse(const string& item, unsigned long* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stoul(data_[item]);
    return out;
  }
  bool Parse(const string& item, unsigned long long* value) {
    bool out = ValidItem(item);
    if (out) *value = std::stoull(data_[item]);
    return out;
  }
  bool ValidItem(const string& item) {
    return data_.find(item) != data_.end();
  }
  string ListAll() {
    string out;
    for (const auto& d : data_) {
      out += d.first + " " + d.second + "\n";
    }
    return out;
  }

  // TODO: adding arbitrary type parser by implenment template<T> stox
  
 private:
  Config();
  Config(Config const&);
  Config& operator=(Config const&);
  ~Config();
  std::unordered_map<string, string> data_;
};

#endif  // CPP_CONFIG_H_
