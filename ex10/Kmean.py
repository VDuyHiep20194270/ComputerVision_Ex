import cv2
import numpy as np
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

def kmeans_image_clustering(image_path, k, output_path):
    # Đọc ảnh
    image = cv2.imread(image_path)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)

    # Reshape ảnh để có được mảng 2D
    pixels = image.reshape((-1, 3))

    # Áp dụng K-means clustering
    kmeans = KMeans(n_clusters=k)
    kmeans.fit(pixels)

    # Lấy các điểm trung tâm cụm
    centers = np.array(kmeans.cluster_centers_, dtype=np.uint8)  # Chuyển đổi sang định dạng hỗ trợ

    # Lấy nhãn của từng điểm ảnh
    labels = kmeans.labels_

    # Tạo ảnh mới với màu của các điểm trung tâm cụm
    segmented_image = centers[labels].reshape(image.shape).astype(np.uint8)  # Chuyển đổi sang định dạng hỗ trợ

    # Ghi ảnh đã phân cụm ra file
    cv2.imwrite(output_path, cv2.cvtColor(segmented_image, cv2.COLOR_RGB2BGR))

    # Hiển thị ảnh gốc và ảnh đã phân cụm
    plt.figure(figsize=(10, 5))
    plt.subplot(1, 2, 1)
    plt.imshow(image)
    plt.title('Ảnh Gốc')

    plt.subplot(1, 2, 2)
    plt.imshow(segmented_image)
    plt.title(f'Phân Cụm (k={k})')

    plt.show()

# Đường dẫn đến ảnh đầu vào
image_path = r'C:\Users\min\RHUST\2023-2024\20231\Computer vision\exercise\ComputerVision_Ex\ex10\phong-nam-valley-cao-bang1.jpg'

# Số lượng cụm màu mong muốn (k)
k_values = [8, 16, 32]

for k in k_values:
    # Đường dẫn để lưu ảnh đã phân cụm
    output_path = f'output_image_k{k}.jpg'
    kmeans_image_clustering(image_path, k, output_path)
