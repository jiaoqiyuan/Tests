import leancloud

leancloud.init("n2HspM41RbogfYToohbhdzcF-gzGzoHsz", "BmbN7noqgmLyN99xJLQfDwYv")

Todo = leancloud.Object.extend('Comment')
query = leancloud.Query(Todo)
query_result = query.get('5cc8012a7b968a0073d8b35b')
print(query_result.get('comment'))
