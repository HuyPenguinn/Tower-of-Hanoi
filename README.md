# Tower of Hanoi

## Giới thiệu
Tower of Hanoi là một trò chơi giải đố cổ điển, nơi người chơi di chuyển các đĩa từ cột ban đầu sang một cột khác theo quy tắc nhất định. Trò chơi có hai chế độ:
- **Chế độ thường**: Chơi tự do, không giới hạn thời gian.
- **Chế độ speedrun**: Chỉ mở khóa sau khi đạt 3 sao ở chế độ thường, yêu cầu giải đố nhanh nhất có thể.

## Hướng dẫn cài đặt

### 1. Cách tải MinGW
MinGW là bộ công cụ biên dịch cần thiết để biên dịch trò chơi.

#### Bước 1: Tải MinGW-w64
- Truy cập trang web chính thức: [https://www.mingw-w64.org/](https://www.mingw-w64.org/)
- Tải phiên bản phù hợp với hệ điều hành của bạn.
- Giải nén và thêm đường dẫn của `bin` vào biến môi trường `PATH`.

#### Bước 2: Kiểm tra cài đặt
Mở terminal hoặc cmd và chạy:
```sh
gcc --version
```
Nếu hiển thị thông tin phiên bản, MinGW đã được cài đặt thành công.

---

### 2. Cách tải thư viện SDL2 và các thư viện liên quan
SDL2 và các thư viện bổ trợ giúp tạo giao diện đồ họa cho trò chơi.

#### Bước 1: Tải thư viện SDL2
- Truy cập trang chủ SDL2: [https://github.com/libsdl-org/SDL/releases/tag/release-2.28.5]
- Tải bản phù hợp với hệ điều hành.
- Giải nén và thêm đường dẫn `lib` và `include` vào cấu hình trình biên dịch.

#### Bước 2: Tải các thư viện bổ trợ
- **SDL2_image**: Hỗ trợ xử lý hình ảnh
  - [https://github.com/libsdl-org/SDL_image/releases]
- **SDL2_ttf**: Hỗ trợ hiển thị font chữ
  - [https://github.com/libsdl-org/SDL_ttf/releases]
- **SDL2_mixer**: Hỗ trợ âm thanh
  - [https://github.com/libsdl-org/SDL_mixer/releases]

Sau khi tải về, thêm đường dẫn `lib` và `include` của các thư viện này vào cấu hình biên dịch tương tự SDL2.

---

## Cách chơi

### 1. Quy tắc chung
- Chỉ có thể di chuyển một đĩa một lần.
- Không được đặt đĩa lớn hơn lên đĩa nhỏ hơn.
- Mục tiêu: Di chuyển tất cả đĩa từ cột đầu tiên sang cột cuối cùng thông qua cột trung gian.

### 2. Chế độ chơi
#### **Chế độ thường**
- Người chơi có thể chơi tùy ý mà không bị giới hạn thời gian.
- Hệ thống đánh giá bằng số sao dựa trên số bước đi:
  - **3 sao**: Hoàn thành trong số bước tối thiểu 31.
  - **2 sao**: Hoàn thành với số bước ≤ 36.
  - **1 sao**: Hoàn thành nhưng vượt quá giới hạn trên.

#### **Chế độ speedrun**
- Chỉ mở khóa khi người chơi đạt **3 sao** ở chế độ thường.
- Người chơi phải hoàn thành trò chơi càng nhanh càng tốt để ghi điểm trên bảng xếp hạng.

---

## Update trong tương lai
- **Bảng xếp hạng speedrun**: Hiển thị thời gian nhanh nhất của người chơi.
