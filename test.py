def find_largest_square_submatrix(matrix):
    rows = len(matrix)
    if rows == 0:
        return 0
    
    cols = len(matrix[0])
    if cols == 0:
        return 0
    
    # Create an auxiliary matrix to store the size of the largest square ending at each cell
    aux = [[0] * cols for _ in range(rows)]
    
    max_side = 0  # To store the maximum side length of the square submatrix
    
    # Initialize the first row and first column of the auxiliary matrix
    for i in range(rows):
        aux[i][0] = matrix[i][0]
        max_side = max(max_side, aux[i][0])
    
    for j in range(cols):
        aux[0][j] = matrix[0][j]
        max_side = max(max_side, aux[0][j])
    
    # Fill in the rest of the auxiliary matrix
    for i in range(1, rows):
        for j in range(1, cols):
            if matrix[i][j] == 1:
                aux[i][j] = min(aux[i-1][j], aux[i][j-1], aux[i-1][j-1]) + 1
                max_side = max(max_side, aux[i][j])
    
    return max_side, aux

def largest_rectangle_histogram(heights):
    stack = []
    max_area = 0
    i = 0
    
    while i < len(heights):
        # If this bar is higher than the bar on top stack, push it to stack
        if not stack or heights[i] >= heights[stack[-1]]:
            stack.append(i)
            i += 1
        else:
            top = stack.pop()
            # Calculate the area with heights[top] stack as smallest bar
            width = i if not stack else i - stack[-1] - 1
            max_area = max(max_area, heights[top] * width)
    
    while stack:
        top = stack.pop()
        width = i if not stack else len(heights) - stack[-1] - 1
        max_area = max(max_area, heights[top] * width)
    
    
    
    return max_area

def maximal_rectangle(matrix):
    if not matrix:
        return 0
    
    rows = len(matrix)
    cols = len(matrix[0])
    heights = [0] * cols
    max_area = 0
    
    for i in range(rows):
        for j in range(cols):
            if matrix[i][j] == 0:
                heights[j] = 0
            else:
                heights[j] += 1
        
        max_area = max(max_area, largest_rectangle_histogram(heights))
        print(heights)
    
    return max_area, heights


def print_matrix(matrix):
    for row in matrix:
        print(" ".join(map(str, row)))

# Example usage
matrix = [
    [1, 0, 1, 0, 0, 1],
    [1, 1, 1, 1, 1, 0],
    [0, 1, 1, 1, 0, 1],
    [0, 1, 0, 0, 0, 0],
    [1, 1, 1, 1, 1, 1],
]

print(largest_rectangle_histogram([2, 1, 5, 6, 2, 3]))
# print("Original matrix:")
# print_matrix(matrix)
# largest_area, new_heights = maximal_rectangle(matrix)
# print("\nLargest area:", largest_area)
