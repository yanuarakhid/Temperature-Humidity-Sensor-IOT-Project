<div class="container">
    <div class="text-center mb-5 mt-5">
        <h1 style="color:red">Suhu : <?= $suhu; ?></h1>
        <h1>Kelemban : <?= $kelembapan; ?></h1>

        <h3>Added Database at <?php date_default_timezone_set('Asia/Jakarta');
                                echo date('m/d/Y H:i:s', $waktu); ?></h3>
    </div>
</div>