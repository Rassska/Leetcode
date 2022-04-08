from copy import deepcopy

class Solution:
  def maxPoints(self, points: List[List[int]]) -> int:

    if not points:
        return 0
    res = max(points[0])

    for r in range(1, len(points)):
        dp = points[r-1]
        for d in range(1, len(points[0])):
            dp[d] = max(dp[d], dp[d-1]-1)


        for e in range(len(points[0])-2, -1, -1):
            dp[e] = max(dp[e], dp[e+1]-1)


        for c in range(len(points[0])):
            points[r][c] += dp[c]

            res = max(res,  points[r][c])

    return res